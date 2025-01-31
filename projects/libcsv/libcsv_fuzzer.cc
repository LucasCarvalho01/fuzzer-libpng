#include <stddef.h>
#include <stdint.h>
#include <csv.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    struct csv_parser parser;
    if (csv_init(&parser, 0) != 0) {
        return 0;
    }

    csv_parse(&parser, (const char *)data, size, NULL, NULL, NULL);
    csv_fini(&parser, NULL, NULL, NULL);

    csv_free(&parser);
    return 0;
}
