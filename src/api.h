/*
 * This file is part of libwebsock
 *
 * Copyright (C) 2012 Payden Sutherland
 *
 * libwebsock is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3 of the License.
 *
 * libwebsock is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libwebsock; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */

#ifndef API_H_
#define API_H_

#include "types.h"

int libwebsock_close(libwebsock_client_state *state);
int libwebsock_close_with_reason(libwebsock_client_state *state, unsigned short code, const char *reason);
int libwebsock_send_binary(libwebsock_client_state *state, char *in_data, unsigned long long payload_len);
int libwebsock_send_text(libwebsock_client_state *state, char *strdata);
int libwebsock_send_text_with_length(libwebsock_client_state *state, char *strdata, unsigned long long payload_len);
void libwebsock_wait(libwebsock_context *ctx);
void libwebsock_bind(libwebsock_context *ctx, char *listen_host, char *port);
libwebsock_context *libwebsock_init(void);
libwebsock_context *libwebsock_init_flags(int flags);

#ifdef WEBSOCK_HAVE_SSL
void libwebsock_bind_ssl(libwebsock_context *ctx, char *listen_host, char *port, char *keyfile, char *certfile);
void libwebsock_bind_ssl_real(libwebsock_context *ctx, char *listen_host, char *port, char *keyfile, char *certfile, char *chainfile);
#endif


#endif /* API_H_ */