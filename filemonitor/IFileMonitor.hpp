#ifndef I_FILE_MONITOR_HPP
#define I_FILE_MONITOR_HPP

class IFileMonitor {
public:
    virtual void startMonitoring() = 0;
    virtual ~IFileMonitor() = default;
};

#endif // IFILE_MONITOR_HPP
