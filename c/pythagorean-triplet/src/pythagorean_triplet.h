#ifndef PYTHAGOREAN_TRIPLET
#define PYTHAGOREAN_TRIPLET

typedef struct triplet_t
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
} triplet_t;

typedef struct triplets_t
{
    unsigned int count;
    triplet_t* triplets;
} triplets_t;

// triplets_with_sum : returns the list of triplets with an input sum
triplets_t* triplets_with_sum(unsigned int sum);

// free_triplets : frees the result obtained from the previous function
void free_triplets(triplets_t* triplets);

#endif
