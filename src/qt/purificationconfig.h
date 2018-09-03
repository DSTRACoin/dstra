#ifndef OBFUSCATIONCONFIG_H
#define OBFUSCATIONCONFIG_H

#include <QDialog>

namespace Ui
{
class PurificationConfig;
}
class WalletModel;

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class PurificationConfig : public QDialog
{
    Q_OBJECT

public:
    PurificationConfig(QWidget* parent = 0);
    ~PurificationConfig();

    void setModel(WalletModel* model);


private:
    Ui::PurificationConfig* ui;
    WalletModel* model;
    void configure(bool enabled, int coins, int rounds);

private slots:

    void clickBasic();
    void clickHigh();
    void clickMax();
};

#endif // OBFUSCATIONCONFIG_H
