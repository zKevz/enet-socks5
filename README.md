# Note

This is a fork and a modified version of [enet](https://github.com/lsalzman/enet).
Because the original [enet](https://github.com/lsalzman/enet) library doesn't support [SOCKS5](https://www.rfc-editor.org/rfc/rfc1928) protocol, we decided to add a support of it.
Not only [SOCKS5](https://www.rfc-editor.org/rfc/rfc1928), we also add a support for Growtopia's Ubisoft Protocol, for both client/server.

# Changes
- [SOCKS5](https://www.rfc-editor.org/rfc/rfc1928) Implementation
- Growtopia's Ubisoft Protocol that is compatible to [SOCKS5](https://www.rfc-editor.org/rfc/rfc1928) protocol aswell

# Usage
To enable [SOCKS5](https://www.rfc-editor.org/rfc/rfc1928) protocol, you will need to write some code just below enet_host_create
```c
ENetSocks5Config config;
config.address.port = 1080; // The SOCKS5 proxy port

const char *proxy_host_ip = "127.0.0.1"; // The SOCKS5 proxy address
if (enet_address_set_host_ip(&config.address, proxy_host_ip)) {
  fprintf(stderr, "Can't bind address to %s\n", proxy_host_ip);
  return EXIT_FAILURE;
}

strcpy(config.username, "proxy-username-here"); // Your SOCKS5 username, or leave blank for no authentication method
strcpy(config.password, "proxy-password-here"); // Your SOCKS5 password, or leave blank for no authentication method

if (enet_host_use_socks5(host, &config)) {
  fprintf(stderr, "Can't bind host to socks5\n");
  return EXIT_FAILURE;
}
```
Enabling Growtopia's Ubisoft Protocol support is as simple as:
```c
enet_host_set_using_new_packet(host, 1);
```

For the full code, check: [test.c](https://github.com/zKevz/enet-socks5/blob/main/test.c)

# Credits
All credits and rights belongs to the author of [enet](https://github.com/lsalzman/enet) library [Lee Salzman](https://github.com/lsalzman)

Other notable people:
- [Abood](https://github.com/AboodTBR)
