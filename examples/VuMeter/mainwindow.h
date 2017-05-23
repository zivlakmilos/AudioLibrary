#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow(void);

private:
    void setupGUI(void);

private slots:
    void open(void);
};

#endif // _MAIN_WINDOW_H_
