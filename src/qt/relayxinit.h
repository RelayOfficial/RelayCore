#ifndef RELAYXINIT_H
#define RELAYXINIT_H

#include <QDialog>

namespace Ui {
class NavTechInit;
}

class NavTechInit : public QDialog
{
    Q_OBJECT

public:
    explicit NavTechInit(QWidget *parent = 0);
    ~NavTechInit();
    QString GetServers();
    void ShowNavtechIntro(bool exitAfter = true);

private:
    Ui::NavTechInit *ui;
};

#endif // RELAYXINIT_H
