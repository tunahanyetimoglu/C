#include <stdio.h>
#include <stdlib.h>

struct point {
        int x;
        int y;
};

struct point *
point_create(int x, int y)
{
        struct point *this =
                (struct point *)malloc(sizeof(struct point));

        this->x = x;
        this->y = y;

        return this;
}
int
is_square(const struct point *this, const struct point *that)
{
        
        return abs(that->x - this->x) == abs(that->y - this-> y);
}


void
point_print(const struct point *this)
{
        printf("(%d,%d)", this->x, this->y);
}

void
point_destroy(struct point *this)
{
        free(this);
}

int
main(void)
{
        struct point *p = point_create(3, 5);
        struct point *q = point_create(5, 7);
        struct point *z = point_create(-1, 8);

        point_print(p),printf("ile");
        point_print(q),printf("noktaları kare ");
        printf("%s.\n" , is_square(p,q) ? "belirtir" : "belirtmez");
        point_print(p),printf("ile");
        point_print(z),printf("noktaları kare ");
        printf("%s.\n" , is_square(p,z) ? "belirtir" : "belirtmez");
        point_destroy(p);
        point_destroy(q);
        point_destroy(z);

        return 0;
}
