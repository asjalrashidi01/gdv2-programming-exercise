#pragma once

#include <QMainWindow>

#include "ui/SettingsWidget.h"
#include "ui_MainWindow.h"

namespace ui {
class MainWindow: public QMainWindow, private Ui::MainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    ui::SettingsWidget* m_settings_widget;
};
} // namespace ui
