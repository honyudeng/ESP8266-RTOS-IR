#pragma once

#include <stdint.h>

typedef struct ir_decoder ir_decoder_t;

typedef int(*ir_decode_t)(ir_decoder_t *decoder, int16_t *pulses, uint16_t count,
                          void *decoded_data, uint16_t *decoded_size);

struct ir_decoder {
    ir_decode_t decode;
};


void ir_rx_init(uint8_t gpio, uint16_t buffer_size);
int ir_recv(ir_decoder_t *decoder, uint32_t timeout, void *recieved_data, uint16_t *received_size);