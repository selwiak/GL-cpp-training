#ifndef I_FILE_UPDATER_HPP
#define I_FILE_UPDATER_HPP

class IFileUpdater{
public:
    virtual void startUpdating() = 0;
    virtual ~IFileUpdater() = default;
};

#endif // IFILE_UPDATER_HPP
