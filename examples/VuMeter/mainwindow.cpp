#include "mainwindow.h"

#include <QtGui>

#include "vumeter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QCoreApplication::setApplicationName(tr("Vu Meter"));
    QCoreApplication::setOrganizationName(tr("Milos Zivlak"));
    QCoreApplication::setOrganizationDomain(tr("https://github.com/zivlakmilos/"));

    setupGUI();
}

MainWindow::~MainWindow(void)
{
}

void MainWindow::setupGUI(void)
{
    QMenu *menuFile = menuBar()->addMenu(tr("&File"));

    QAction *actionOpen = menuFile->addAction(tr("&Open"));
    actionOpen->setShortcut(tr("Ctrl+O"));
    connect(actionOpen, SIGNAL(triggered(bool)),
            this, SLOT(open()));

    QAction *actionQuit = menuFile->addAction(tr("&Quit"));
    actionQuit->setShortcut(tr("Ctrl+Q"));
    connect(actionQuit, SIGNAL(triggered(bool)),
            qApp, SLOT(quit()));

    setCentralWidget(new VuMeter(this));
}

void MainWindow::open(void)
{
    QString fileName =
        QFileDialog::getOpenFileName(this, tr("Open Song File"),
                                     QString(), tr("WAV | *.wav"));

    if(!fileName.isEmpty())
    {
        VuMeter *vuMeter = static_cast<VuMeter*>(centralWidget());
        vuMeter->openFile(fileName);
    }
}
