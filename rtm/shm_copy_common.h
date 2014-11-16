
#define COPY_TO_SHM(x, size) do { \
    memcpy(s, (x), (size)); s += (size); \
} while (0)



#define COPY_TO_LOCAL(x, size) do { \
    memcpy((x), s, (size)); s += (size); \
} while (0)

