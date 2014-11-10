#include "output.hpp"

using namespace VPZ::APKStudio::Helpers;

namespace VPZ {
namespace APKStudio {
namespace Components {

Output::Output(QWidget *parent) :
    Dockable(translate("title_dock"), parent)
{
    tabs = new QTabWidget(this);
    tabs->setMinimumSize(64, 64);
    tabs->setTabPosition(QTabWidget::South);
    createAPKStudioTab();
    createApktoolTab();
    createADBTab();
    setFeatures(features() | QDockWidget::DockWidgetVerticalTitleBar);
    setObjectName("output");
    setWidget(tabs);
}

void Output::createADBTab()
{
    QWidget *tab = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(tabs);
    Terminal *terminal = new Terminal("adb", tab);
    connections.append(connect(ADB::instance(), SIGNAL(commandExecuted(QStringList, QStringList)), terminal, SLOT(onCommandExecuted(QStringList, QStringList))));
    layout->addWidget(terminal);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(1);
    tab->setLayout(layout);
    tabs->addTab(tab, translate("tab_adb"));
}

void Output::createAPKStudioTab()
{
    QWidget *tab = new QWidget(tabs);
    QVBoxLayout *layout = new QVBoxLayout(tab);
    apk_studio = new QTextEdit(tab);
    apk_studio->setReadOnly(true);
    layout->addWidget(apk_studio);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(1);
    tab->setLayout(layout);
    tabs->addTab(tab, translate("tab_apk_studio"));
}

void Output::createApktoolTab()
{
    QWidget *tab = new QWidget(tabs);
    QVBoxLayout *layout = new QVBoxLayout(tab);
    Terminal *terminal = new Terminal("java", tab);
    connections.append(connect(apktool::instance(), SIGNAL(commandExecuted(QStringList, QStringList)), terminal, SLOT(onCommandExecuted(QStringList, QStringList))));
    layout->addWidget(terminal);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(1);
    tab->setLayout(layout);
    tabs->addTab(tab, translate("tab_apk_tool"));
}

} // namespace Components
} // namespace APKStudio
} // namespace VPZ
