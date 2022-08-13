#include <stdio.h>
#include <enet/enet.h>

int main() {
  if (enet_initialize() != 0) {
    fprintf(stderr, "Can't initialize ENet\n");
    return EXIT_FAILURE;
  }

  ENetHost *host = enet_host_create(NULL, 1024, 1, 0, 0);
  if (!host) {
    fprintf(stderr, "Can't create host\n");
    return EXIT_FAILURE;
  }

  ENetSocks5Config config;
  config.address.port = 1080;

  const char *proxy_host_ip = "127.0.0.1";
  if (enet_address_set_host_ip(&config.address, proxy_host_ip)) {
    fprintf(stderr, "Can't bind address to %s\n", proxy_host_ip);
    return EXIT_FAILURE;
  }

  strcpy(config.username, "proxy-username-here");
  strcpy(config.password, "proxy-password-here");

  if (enet_host_use_socks5(host, &config)) {
    fprintf(stderr, "Can't bind host to socks5\n");
    return EXIT_FAILURE;
  }

  ENetAddress address;
  address.port = 17198;

  const char *target_ip = "69.420.69.420"; // for example we want to connect to 69.420.69.420
  if (enet_address_set_host_ip(&address, target_ip) != 0) {
    fprintf(stderr, "Can't set address host ip to %s\n", target_ip);
    return EXIT_FAILURE;
  }

  if (!enet_host_connect(host, &address, 1, 0)) {
    fprintf(stderr, "Failed to connect to server\n");
    return EXIT_FAILURE;
  }

  printf("Client ready\n");

  ENetEvent event;
  while (1) {
    while (enet_host_service(host, &event, 10) > 0) {
        printf("Received event: %d\n", event.type);
    }
  }
}