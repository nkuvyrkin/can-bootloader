#ifndef CAN_DATAGRAM_H
#define CAN_DATAGRAM_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint32_t crc;

    uint8_t *destination_nodes;
    uint8_t destination_nodes_len;

    uint8_t *data;
    uint16_t data_len;

    int _crc_bytes_read;
    uint8_t _destination_nodes_read;
    uint16_t _data_bytes_read;
    uint16_t _data_buffer_size;
    int _reader_state;
} can_datagram_t;

/** Sets the structure field to default values. */
void can_datagram_init(can_datagram_t *dt);

/** Sets the buffer to use to store destination adresses. */
void can_datagram_set_adress_buffer(can_datagram_t *dt, uint8_t *buf);

/** Sets the buffer to use for data storage. */
void can_datagram_set_data_buffer(can_datagram_t *dt, uint8_t *buf, size_t buf_size);

/** Inputs a byte into the datagram. */
void can_datagram_input_byte(can_datagram_t *dt, uint8_t val);

/** Returns true if the datagram is complete (all data were read). */
bool can_datagram_is_complete(can_datagram_t *dt);

/** Returns true if the datagram is valid (complete and CRC match). */
bool can_datagram_is_valid(can_datagram_t *dt);

/** Signals to the parser that we are at the start of a datagram.
 *
 * The start of datagram comes from the Message ID (physical layer).
 */
void can_datagram_start(can_datagram_t *dt);

#ifdef __cplusplus
}
#endif

#endif