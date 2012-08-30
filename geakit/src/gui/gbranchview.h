#ifndef GBRANCHVIEW_H
#define GBRANCHVIEW_H

#include <QWidget>
#include <git2.h>
#include <QProcess>
#include <QList>
#include <QHash>
class QScrollArea;
class QGroupBox;
class QPushButton;
class GitCommand;
class QComboBox;
class QVBoxLayout;

class GBranchView : public QWidget
{
  Q_OBJECT
  public:
    explicit GBranchView(QWidget* parent = 0, git_repository* repo = 0);
    void setPassword(const QString& password);
    ~GBranchView();
  signals:
    void branchChanged();
  public slots:
    void updateView();
  private slots:
    void onChangeButtonClicked(int id);
    void onMergeButtonClicked(int id);
    void onRemoteButtonClicked(int id);
    void onPushButtonClicked();
    void onFetchButtonClicked();
    void onNewBranchButtonClicked();
    void onNewRemoteButtonClicked();
    void onRmBranchButtonClicked(int id);
  private:
    QString getRemoteUrl(const QString& remoteName);
    void setupLocalBranchesArea();
    void setupRemoteBranchesArea();
    void freeRemoteArea();
  private:
    git_repository* m_repo;
    QPushButton* m_pushButton;
    QPushButton* m_fetchButton;
    QPushButton* m_newBranchButton;
    QPushButton* m_newRemoteButton;
    QGroupBox* m_localBranchArea;
    QList<QGroupBox*> m_remoteAreaList; 
    QScrollArea* m_mainArea;
    QStringList m_branchList;
    QStringList m_remoteList;
    QHash<QString, QStringList> m_remoteBranchesHash;
    QString m_password;
    QComboBox* m_remoteNames;
    QVBoxLayout* m_mainLayout;

    GitCommand* m_command;
};
#endif
