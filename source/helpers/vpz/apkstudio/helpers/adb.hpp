#ifndef VPZ_APKSTUDIO_HELPERS_ADB_HPP
#define VPZ_APKSTUDIO_HELPERS_ADB_HPP

#include <QRegularExpression>
#include <QVector>
#include "resources/constant.hpp"
#include "resources/variant.hpp"
#include "cli.hpp"
#include "settings.hpp"

namespace VPZ {
namespace APKStudio {
namespace Helpers {

class ADB : public CLI
{
    Q_OBJECT
private:
    static ADB *self;
public:
    explicit ADB(QObject * = 0);
    QVector<Resources::Application> applications(const QString &) const;
    bool chmod(const QString &, const QString &, const QString &, bool = false) const;
    bool chown(const QString &, const QString &, const QString &, const QString &, bool = false) const;
    bool copy(const QString &, const QString &, const QString &, bool = false) const;
    bool create(const QString &, const QString &) const;
    QVector<Resources::Device> devices() const;
    bool enable(const QString &, const QString &, bool) const;
    QVector<Resources::File> files(const QString &, const QString &) const;
    QString IMEI(const QString &) const;
    bool install(const QString &, const QString &) const;
    static ADB *instance();
    void kill();
    bool move(const QString &, const QStringList &, const QString &) const;
    QVector<Resources::Music> music(const QString &) const;
    QVector<Resources::Partition> partitions(const QString &) const;
    QVector<Resources::Photo> photos(const QString &) const;
    QMap<QString, QString> properties(const QString &) const;
    bool pull(const QString &, const QString &, const QString &) const;
    bool push(const QString &, const QString &, const QString &) const;
    QString quote(const QString &) const;
    QString quote(const QStringList &) const;
    void reboot(const QString &, const Resources::Reboot &);
    bool rename(const QString &, const QString &, const QString &) const;
    bool remount(const QString &, const Resources::Partition &);
    bool remove(const QString &, const QString &, bool = false) const;
    void screenshot(const QString &, const QString &);
    void shell(const QString &);
    void start();
    bool uninstall(const QString &, const QString &) const;
    bool unmount(const QString &, const Resources::Partition &) const;
    QVector<Resources::Video> videos(const QString &) const;
};

} // namespace Helpers
} // namespace APKStudio
} // namespace VPZ

#endif // VPZ_APKSTUDIO_HELPERS_ADB_HPP
