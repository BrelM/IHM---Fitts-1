#ifndef ZOOMABLECHARTVIEW_H
#define ZOOMABLECHARTVIEW_H


#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QGraphicsScene>


    class ZoomableChartView : public QChartView {
public:
        ZoomableChartView();
        ZoomableChartView(QChart *chart, QWidget *parent);

protected:
    void wheelEvent(QWheelEvent *event) override;

    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    qreal currentZoomLevel;
    const qreal minZoomLevel;
    const qreal maxZoomLevel;
    QRectF originalRect;
};




#endif // ZOOMABLECHARTVIEW_H
