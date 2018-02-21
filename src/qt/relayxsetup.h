#ifndef RELAYXSETUP_H
#define RELAYXSETUP_H

#include "wallet/relayx.h"

#include <QDialog>
#include <QVBoxLayout>

namespace Ui {
class navtechsetup;
}

class navtechsetup : public QDialog
{
    Q_OBJECT

public:
    explicit navtechsetup(QWidget *parent = 0);
    ~navtechsetup();

private:
    Ui::navtechsetup *ui;

public Q_SLOTS:
    void reloadNavtechServers();
    void addNavtechServer();
    void removeNavtechServer();
    void getinfoNavtechServer();
    void showButtons(bool show=true);
    void showNavtechIntro();

};

#endif // RELAYXSETUP_H
