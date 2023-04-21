#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QFrame>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("Image Viewer");

    QLabel *imageLabel = new QLabel;
    QPixmap pixmap("image.jpg");

    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        imageLabel->setAlignment(Qt::AlignCenter);
    } else {
        imageLabel->setText("Unable to load image.");
    }

    QFrame *frame = new QFrame;
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Sunken);
    frame->setLineWidth(2);
    frame->setLayout(new QVBoxLayout);
    frame->layout()->addWidget(imageLabel);

    QLabel *fileNameLabel = new QLabel("image.jpg");
    fileNameLabel->setAlignment(Qt::AlignCenter);

    QFrame *rect = new QFrame;
    rect->setFrameShape(QFrame::StyledPanel);
    rect->setFrameShadow(QFrame::Sunken);
    rect->setLineWidth(2);
    rect->setLayout(new QVBoxLayout);
    rect->layout()->addWidget(fileNameLabel);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(frame);
    layout->addWidget(rect);
    window->setLayout(layout);

    window->show();

    return a.exec();
}
