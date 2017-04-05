#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>

namespace Ui {
class CameraWidget;
}

class CameraWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CameraWidget(QWidget *parent = 0);
    ~CameraWidget();

private slots:
    void on_StartStopCameraButton_clicked();

private:
    Ui::CameraWidget *ui;
};

#endif // CAMERAWIDGET_H
