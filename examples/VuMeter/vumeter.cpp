#include "vumeter.h"

#include <QtGui>

#include <zaudio/sdl/audioloadersdl.h>
#include <zaudio/sdl/audiosamplesdl.h>

VuMeter::VuMeter(QWidget *parent)
    : QWidget(parent)
{
    connect(this, SIGNAL(doRepaint()),
            this, SLOT(repaint()));
}

VuMeter::~VuMeter(void)
{
}

void VuMeter::openFile(const QString &filePath)
{
    std::shared_ptr<IAudioSample> sample(AudioLoaderSDL::loadWav(filePath.toStdString()));
    m_player.play(sample);
    m_player.setOnUpdateListener([this](const float *data, size_t lenght) {
            onPlayerUpdate(data, lenght);
        });
}

void VuMeter::onPlayerUpdate(const float *data, size_t lenght)
{
    m_amplitude = data[0] + 1;
    m_amplitude /= 2;

    emit doRepaint();
}

void VuMeter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    int amplitude = m_amplitude * height();
    painter.drawRect(0, 0, 10, amplitude);

    QWidget::paintEvent(event);
}

void VuMeter::repaint(void)
{
    update();
}
