//2-3.c
int ge(float x, float y) {
    
    unsigned int ux = *((unsigned int*) &x); // convert x raw bits 
    unsigned int uy = *((unsigned int*) &y);// convert y raw bits
    unsigned int sx = ux >> 31; // extract sign bit of ux 
    unsigned int sy = uy >> 31; // extract sign bit of uy
    ux <<= 1; // drop sign bit of ux
    uy <<= 1; // drop sign bit of uy
    
    // TODO: return using sx, sy, ux, uy
    //will be explained from left to right
    /*	checks if x is greater when both are positive
	or  return true when both 0
	or  when both negative return true if y has a greater number
	or  return true if y is negative and x is positive    
    */

    return (((ux >= uy) && ((sx == 0 && sy == 0)) || ((ux == 0) && (uy == 0)) || ((ux <= uy) && ((sx == 1) && (sy == 1))) || (sx < sy)));
    // return 1 if x is >= y, 0 otherwise

}

int main(){
    
    printf("%d\n",ge(0.0f, 0.0f));   //1
    printf("%d\n",ge(-0.0f, 0.0f));  //1
    printf("%d\n",ge(-1.0f, 0.0f));  //0
    printf("%d\n",ge(0.0f, 1.0f));   //0
    printf("%d\n",ge(1.0f, 0.0f));   //1
    printf("%d\n",ge(0.0f, -1.0f));  //1
    
    return 0;
}