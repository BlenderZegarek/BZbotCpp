#ifndef PING_H
#define PING_H

#include <dpp/dpp.h>
#include "../utils/utils.h"

bool _ping(const dpp::slashcommand_t& event, int &exit_code, colors_t colors);
void _register_ping(dpp::cluster& bot);

#endif /* PING_H */

