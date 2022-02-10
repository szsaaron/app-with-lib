#ifndef ORD_SDK_ORD_DRIVER_H_
#define ORD_SDK_ORD_DRIVER_H_

#include "ord/ord_types.h"
#include "ord/ord_driver_net.h"
#include "ord/ord_driver_impl.h"

namespace ord_sdk
{
  
class Impl;

class OrdDriver 
{
public:
  OrdDriver(const SocketAddress& sensor);
  virtual ~OrdDriver();
  void setTimeout(int timeout);
  virtual error_t open();
  bool isOpened() const;
  virtual void close();

  error_t setLidarIPAddress(in_addr_t address);
  error_t setLidarNetPort(in_port_t port);
  error_t setLidarMacAddress(const uint8_t HWaddr[]);
  error_t setLidarSubnetMask(in_addr_t subnet);
  error_t setScanSpeed(uint32_t speed);
  error_t setTailFilterLevel(uint32_t level);
  error_t setTimestamp(uint32_t timestamp);
  error_t setScanDirection(uint32_t direction);
  error_t trackConnect();
  error_t enableMeasure();
  error_t disableMeasure();
  error_t enabelDataStream();
  error_t disableDataStream();
  error_t setWorkState(uint32_t work_state);
  error_t setDeviceSN(std::string device_sn);
  error_t setProductModel(std::string product_model);
  error_t applyConfigs();
  error_t deviceReboot();
  error_t deviceUpgrade();

  error_t getLidarIPAddress(in_addr_t& address);
  error_t getLidarNetPort(in_port_t& port);
  error_t getLidarMacAddress(uint8_t HWaddr[]);
  error_t getLidarSubnetMask(in_addr_t& subnet);
  error_t getScanSpeed(uint32_t& speed);
  error_t getTailFilterLevel(uint32_t& level);
  error_t getTimestamp(uint32_t& timestamp);
  error_t getMotorSpeed(uint32_t& motor_speed);
  error_t getInternalTemperature(float& inter_temp);
  error_t getAPDHighVoltage(float& high_voltage);
  error_t getWorkState(uint32_t& work_state);
  error_t getSyncStatus(uint32_t& sync_status);
  error_t getFirmwareVersion(std::string& firmware_version);
  error_t getHardwareVersion(std::string& hardware_version);
  error_t getDeviceSN(std::string& device_sn);
  error_t getProductModel(std::string& product_model);
  error_t getSDKVersion(std::string& sdk_version);
  error_t getScanDirection(uint32_t& direction);

  error_t getOperationMode(uint32_t& operation_mode);
  error_t beginUpdate();
  error_t endUpdate();
  error_t writeData(const uint8_t bindata[], int length);
  error_t verifyHash(const uint8_t expected[], bool& passed);
  error_t commitUpdate();

  error_t getScanFrameData(ScanFrameData& scan_frame_data);
  error_t getScanBlockData(ScanBlockData& scan_block_data);

public:
  static const int HASH_LENGTH = 16;

protected:
  std::unique_ptr<SocketAddress> sensor_;
  std::unique_ptr<Impl> impl_;
};


}

#endif
