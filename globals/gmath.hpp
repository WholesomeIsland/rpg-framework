// gmath.hpp - global math functions


// damage calc formula taken from here https://jmargaris.substack.com/p/you-smack-the-rat-for-damage
// graph from that blog post that graphs this equasion vs fire emblem https://www.desmos.com/calculator/r4djk3ewoo
//returns the ammount of damage taken
int dmgCalc(int atk, int def){
    if(atk >= def){
        return atk-(def/2);
    }
    else{
        return atk * (atk/(2*def));
    }

}