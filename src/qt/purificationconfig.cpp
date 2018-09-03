#include "purificationconfig.h"
#include "ui_purificationconfig.h"

#include "bitcoinunits.h"
#include "guiconstants.h"
#include "init.h"
#include "optionsmodel.h"
#include "walletmodel.h"

#include <QKeyEvent>
#include <QMessageBox>
#include <QPushButton>
#include <QSettings>

PurificationConfig::PurificationConfig(QWidget* parent) : QDialog(parent),
                                                        ui(new Ui::PurificationConfig),
                                                        model(0)
{
    ui->setupUi(this);

    connect(ui->buttonBasic, SIGNAL(clicked()), this, SLOT(clickBasic()));
    connect(ui->buttonHigh, SIGNAL(clicked()), this, SLOT(clickHigh()));
    connect(ui->buttonMax, SIGNAL(clicked()), this, SLOT(clickMax()));
}

PurificationConfig::~PurificationConfig()
{
    delete ui;
}

void PurificationConfig::setModel(WalletModel* model)
{
    this->model = model;
}

void PurificationConfig::clickBasic()
{
    configure(true, 1000, 2);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("Purification Configuration"),
        tr(
            "Purification was successfully set to basic (%1 and 2 rounds). You can change this at any time by opening DSTRA's configuration screen.")
            .arg(strAmount));

    close();
}

void PurificationConfig::clickHigh()
{
    configure(true, 1000, 8);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("Purification Configuration"),
        tr(
            "Purification was successfully set to high (%1 and 8 rounds). You can change this at any time by opening DSTRA's configuration screen.")
            .arg(strAmount));

    close();
}

void PurificationConfig::clickMax()
{
    configure(true, 1000, 16);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("Purification Configuration"),
        tr(
            "Purification was successfully set to maximum (%1 and 16 rounds). You can change this at any time by opening DSTRA's configuration screen.")
            .arg(strAmount));

    close();
}

void PurificationConfig::configure(bool enabled, int coins, int rounds)
{
    QSettings settings;

    settings.setValue("nPurificationRounds", rounds);
    settings.setValue("nAnonymizeDSTRAAmount", coins);

    nPurificationRounds = rounds;
    nAnonymizeDSTRAAmount = coins;
}
