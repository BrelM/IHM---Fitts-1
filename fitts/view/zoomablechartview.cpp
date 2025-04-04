#include "zoomablechartview.h"


ZoomableChartView::ZoomableChartView()
    : currentZoomLevel(1.0),
    minZoomLevel(0.5),
    maxZoomLevel(5.0)
{}

ZoomableChartView::ZoomableChartView(QChart *chart, QWidget *parent = nullptr)
    : QChartView(chart, parent),
    currentZoomLevel(1.0),
    minZoomLevel(0.5),
    maxZoomLevel(5.0)
{
    setDragMode(QGraphicsView::ScrollHandDrag); // Enables panning
    originalRect = chart->plotArea();
}


void ZoomableChartView::wheelEvent(QWheelEvent *event) {
    QPointF mousePos = event->position();
    QPointF chartPos = chart()->mapToValue(mousePos);

    qreal factor = (event->angleDelta().y() > 0) ? 1.1 : 0.9;
    qreal newZoom = currentZoomLevel * factor;

    if (newZoom < minZoomLevel || newZoom > maxZoomLevel) {
        event->accept();
        return;
    }

    chart()->zoom(factor);
    currentZoomLevel = newZoom;

    // Center zooming on mouse position
    QPointF newCenter = chart()->mapToPosition(chartPos);
    QPointF delta = mousePos - newCenter;
    chart()->scroll(-delta.x(), delta.y());

    event->accept();
}

void ZoomableChartView::mouseDoubleClickEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    chart()->zoomReset();
    currentZoomLevel = 1.0;
}
