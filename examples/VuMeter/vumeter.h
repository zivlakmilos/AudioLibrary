#ifndef _VU_METER_H_
#define _VU_METER_H_

#include <QWidget>

#include <zaudio/sdl/audioplayersdl.h>

class VuMeter : public QWidget
{
    Q_OBJECT

public:
    explicit VuMeter(QWidget *parent = 0);
    virtual ~VuMeter(void);

    void openFile(const QString &filePath);

protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    void onPlayerUpdate(const float *data, size_t lenght);

    AudioPlayerSDL m_player;
    double m_amplitude;

signals:
    void doRepaint(void);

private slots:
    void repaint(void);
};

#endif // _VU_METER_H_
