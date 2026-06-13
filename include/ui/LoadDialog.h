#pragma once

#include <QDialog>
#include <glm/glm.hpp>

#include "ui_LoadDialog.h"

namespace ui {
class LoadDialog: public QDialog, Ui::LoadDialog {
    Q_OBJECT

public:
    explicit LoadDialog(QWidget* parent = nullptr);

signals:
    void onLoad(const std::string& path, const glm::ivec3& dimensions);
};
} // namespace ui
