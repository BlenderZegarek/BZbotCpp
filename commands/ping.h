#include <dpp/dpp.h>

#ifndef PING_H
#define PING_H

bool _ping(const dpp::slashcommand_t& event, int &exit_code);
void _register_ping(dpp::cluster& bot);

#endif /* PING_H */

