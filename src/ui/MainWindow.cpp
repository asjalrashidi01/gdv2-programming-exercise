#include "ui/MainWindow.h"

ui::MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    m_settings_widget(new ui::SettingsWidget(true, false, false, true, this)) {
    setupUi(this);
    addDockWidget(Qt::RightDockWidgetArea, m_settings_widget);
    m_render_widget->setRenderChecks(true, false, false, true);
    connect(m_settings_widget, &ui::SettingsWidget::onRenderChecksChanged, m_render_widget, &ui::RenderWidget::setRenderChecks);
    connect(m_settings_widget, &ui::SettingsWidget::onGenerateVolume, m_render_widget, &ui::RenderWidget::generateVolumeMesh);
    connect(m_settings_widget, &ui::SettingsWidget::onGenerateTriviate, m_render_widget, &ui::RenderWidget::generateTriviateMesh);
}

ui::MainWindow::~MainWindow() {
}
