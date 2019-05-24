#include "netlib.h"

int      connect_clients();
int      disconnect_clients();
int      init_jobs();
double   calculate();

static uint64_t  nclients = 0;
static in_port_t tcp_port = 0;
static in_port_t udp_port = 0;

int main( int argc, char* argv[])
{
    if ( argc != 4)
        HANDLE_ERROR_EN( "Invalid number of args, expected - 3: "
                         "nclients, udp_port, tcp_port\n", EINVAL);

    CHECK( ( nclients = str_2_uint( argv[1])));

    uint16_t port = 0;
    
    CHECK( ( port = str_2_uint( argv[2])));
    udp_port = htons( port);

    CHECK( ( port = str_2_uint( argv[3])));
    tcp_port = htons( port);

    CHECK( connect_clients());

    CHECK( init_jobs());

    double result = 0.;

    CHECK( ( result = calculate()));

    CHECK( disconnect_clients());

    printf( "Result is %lg\n", result);

    exit( EXIT_SUCCESS);
}

