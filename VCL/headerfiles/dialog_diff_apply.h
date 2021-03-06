#ifndef DIALOG_DIFF_APPLY_H
#define DIALOG_DIFF_APPLY_H

#include "GeneratedFiles/ui_dialog_diffApply.h"

#include <QDialog>

class DialogDiffApply : public QDialog, public Ui::DialogDiffApply
{
    Q_OBJECT
private:
    enum FileType
    {
        Diff = 0,
        Any
    };
    QString selectFile(FileType f);
private slots:
    
    void onSelectBase();
    void onSelectDiff();
    void onValidateInputs();
public:
    DialogDiffApply(QWidget *parent);
    ~DialogDiffApply();
    QString getBasePath();
    QString getDiffPath();
};

#endif // !DIALOG_DIFF_APPLY_H
