/*
 * RFHelper.h
 * Copyright (C) 2016-2020 Linar Yusupov
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef RFHELPER_H
#define RFHELPER_H

#include <nRF905.h>
#include <TimeLib.h>

#include <lmic.h>
#include <hal/hal.h>
#include <lib_crc.h>
#include <protocol.h>
#include <freqplan.h>

#include "SoftRF.h"
#include "GNSSHelper.h"
#include "Protocol_Legacy.h"
#include "Protocol_OGNTP.h"
#include "Protocol_P3I.h"
#include "Protocol_FANET.h"
#include "Protocol_UAT978.h"

#define maxof2(a,b)       (a > b ? a : b)
#define maxof3(a,b,c)     maxof2(maxof2(a,b),c)
#define maxof5(a,b,c,d,e) maxof2(maxof2(a,b),maxof3(c,d,e))

/* Max. paket's payload size for all supported RF protocols */
//#define MAX_PKT_SIZE  32 /* 48 = UAT LONG_FRAME_DATA_BYTES */
#define MAX_PKT_SIZE  maxof5(LEGACY_PAYLOAD_SIZE, OGNTP_PAYLOAD_SIZE, \
                             P3I_PAYLOAD_SIZE, FANET_PAYLOAD_SIZE, \
                             UAT978_PAYLOAD_SIZE)

#define RXADDR {0x31, 0xfa , 0xb6} // Address of this device (4 bytes)
#define TXADDR {0x31, 0xfa , 0xb6} // Address of device to send to (4 bytes)

enum
{
  RF_IC_NONE,
  RF_IC_NRF905,
  RF_IC_SX1276,
  RF_IC_CC13XX,
  RF_IC_S7XG,
  RF_DRV_OGN
};

enum
{
  RF_TX_POWER_FULL,
  RF_TX_POWER_LOW,
  RF_TX_POWER_OFF
};

typedef struct rfchip_ops_struct {
  byte type;
  const char name[8];
  bool (*probe)();
  void (*setup)();
  void (*channel)(uint8_t);
  bool (*receive)();
  void (*transmit)();
  void (*shutdown)();
} rfchip_ops_t;

String Bin2Hex(byte *, size_t);
uint8_t parity(uint32_t);

byte    RF_setup(void);
void    RF_SetChannel(void);
void    RF_loop(void);
size_t  RF_Encode(ufo_t *);
bool    RF_Transmit(size_t, bool);
bool    RF_Receive(void);
void    RF_Shutdown(void);
uint8_t RF_Payload_Size(uint8_t);

bool nrf905_probe(void);
void nrf905_setup(void);
void nrf905_channel(uint8_t);
bool nrf905_receive(void);
void nrf905_transmit(void);
void nrf905_shutdown(void);

bool sx1276_probe(void);
void sx1276_setup(void);
void sx1276_channel(uint8_t);
bool sx1276_receive(void);
void sx1276_transmit(void);
void sx1276_shutdown(void);

bool cc13xx_probe(void);
void cc13xx_setup(void);
void cc13xx_channel(uint8_t);
bool cc13xx_receive(void);
void cc13xx_transmit(void);
void cc13xx_shutdown(void);

bool s7xg_probe(void);
void s7xg_setup(void);
void s7xg_channel(uint8_t);
bool s7xg_receive(void);
void s7xg_transmit(void);
void s7xg_shutdown(void);

bool ognrf_probe(void);
void ognrf_setup(void);
void ognrf_channel(uint8_t);
bool ognrf_receive(void);
void ognrf_transmit(void);
void ognrf_shutdown(void);

extern byte TxBuffer[MAX_PKT_SIZE], RxBuffer[MAX_PKT_SIZE];
extern unsigned long TxTimeMarker;

extern const rfchip_ops_t *rf_chip;
extern bool RF_SX1276_RST_is_connected;
extern size_t (*protocol_encode)(void *, ufo_t *);
extern bool (*protocol_decode)(void *, ufo_t *, ufo_t *);

extern int8_t RF_last_rssi;

#endif /* RFHELPER_H */
