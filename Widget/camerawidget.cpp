#include "camerawidget.h"
#include "ui_camerawidget.h"
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QtWidgets>
#include <QDebug>
#include <iostream>

Q_DECLARE_METATYPE(QCameraInfo)

CameraWidget::CameraWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraWidget)
{
    ui->setupUi(this);

    QActionGroup *videoDevicesGroup = new QActionGroup(this);
    videoDevicesGroup->setExclusive(true);
    qDebug() << "C++ Style Debug Message";
    foreach (const QCameraInfo &cameraInfo, QCameraInfo::availableCameras())
    {
        qDebug() << cameraInfo.deviceName().toStdString().c_str();
        QAction *videoDeviceAction = new QAction(cameraInfo.description(), videoDevicesGroup);
        videoDeviceAction->setCheckable(true);
        videoDeviceAction->setData(QVariant::fromValue(cameraInfo));
        if (cameraInfo == QCameraInfo::defaultCamera())
            videoDeviceAction->setChecked(true);

        ui->SelectedCameraComboBox->addAction(videoDeviceAction);
    }
}

CameraWidget::~CameraWidget()
{
    delete ui;
}

void CameraWidget::on_StartStopCameraButton_clicked()
{

}
