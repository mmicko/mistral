#ifndef HPS_H
#define HPS_H

#include "p2p.h"
#include "p2r.h"

#include <unordered_map>

enum hps_index_t {
  I_HPS_BOOT,
  I_HPS_CLOCKS,
  I_HPS_CLOCKS_RESETS,
  I_HPS_CROSS_TRIGGER,
  I_HPS_DBG_APB,
  I_HPS_DMA,
  I_HPS_FPGA2HPS,
  I_HPS_FPGA2SDRAM,
  I_HPS_HPS2FPGA,
  I_HPS_HPS2FPGA_LIGHT_WEIGHT,
  I_HPS_INTERRUPTS,
  I_HPS_JTAG,
  I_HPS_LOAN_IO,
  I_HPS_MPU_EVENT_STANDBY,
  I_HPS_MPU_GENERAL_PURPOSE,
  I_HPS_PERIPHERAL_CAN,
  I_HPS_PERIPHERAL_EMAC = I_HPS_PERIPHERAL_CAN + 2,
  I_HPS_PERIPHERAL_I2C = I_HPS_PERIPHERAL_EMAC + 2,
  I_HPS_PERIPHERAL_NAND = I_HPS_PERIPHERAL_I2C + 4,
  I_HPS_PERIPHERAL_QSPI,
  I_HPS_PERIPHERAL_SDMMC,
  I_HPS_PERIPHERAL_SPI_MASTER,
  I_HPS_PERIPHERAL_SPI_SLAVE = I_HPS_PERIPHERAL_SPI_MASTER + 2,
  I_HPS_PERIPHERAL_UART = I_HPS_PERIPHERAL_SPI_SLAVE + 2,
  I_HPS_PERIPHERAL_USB = I_HPS_PERIPHERAL_UART + 2,
  I_HPS_STM_EVENT = I_HPS_PERIPHERAL_USB + 2,
  I_HPS_TEST,
  I_HPS_TPIU_TRACE,
  I_HPS_COUNT
};

class HPSLoader {
public:
  std::vector<xycoords> data;

  HPSLoader(const P2PLoader &p2p, const P2RLoader &p2r);

private:
  std::unordered_map<int, int> hpsmap;

  void lookup(pnode_coords p);
};

#endif
