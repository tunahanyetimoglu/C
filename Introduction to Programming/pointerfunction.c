#include <stdio.h>
void func( int paramter );
// function main begins program execution
int main( void )
{
void ( *funcPtr )( int ) = &func;
( *funcPtr )( 10 );
return 0;
} // end main
void func( int parameter ){
printf( "Value:%d\n", parameter );
}
