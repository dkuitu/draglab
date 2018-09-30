/*
 * This program takes arguments that will calulate the time it takes for a object to fall
 * from a set height and also determines terminal velocity
 *
 * David Kuitunen
 * Jan 17, 2017
 */

// Include header files that contain descriptions of library functions that we want to use
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    //set constants and variables that will be used in calculation
    const double P = 1.2754; //air density kg/m^3
    const double G = 9.80667; //acc of gravity m/s^2
    const int MIL = 1.0e6;
    double height, mass, dragCoefficient, crossSectionalArea, timeStep, time, vel, fdrag, fgrav, fnet, termvel;

    //get height(m) variable from user
    printf("Enter the height in metres: ");
    scanf("%lf",&height);
    //get mass(kg) variable from user
    printf("Enter the mass in kg: ");
    scanf("%lf",&mass);
    //get drag coefficient variable from user
    printf("Enter the drag coefficient: ");
    scanf("%lf",&dragCoefficient);
    //get cross-sectional area from user
    printf("Enter the cross-sectional area: ");
    scanf("%lf",&crossSectionalArea);
    //get time step size from user
    printf("Enter the time step size: ");
    scanf("%lf",&timeStep);

    //initialize net force to the mass(kg)*G(m/s^2)
    fnet = mass*G;

    printf("\tTime\tHeight\tVelocity\tIteration");
    for(int i = 0; i <= MIL && height >= 0; i++ ) {
        printf("\n\t%3.2f\t%3.1f\t%3.1f\t%d",time, height, vel, i);
        // increment velocity by netforce(kg*m/s^2)/mass(kg)*timeStep(s) = velocity(m/s)
        vel += (fnet/mass)*timeStep;
        //calculate force of drag(kg*m/s^2)
        fdrag = -dragCoefficient*P*crossSectionalArea*pow(vel,2)/2;
        //calculate force of gravity(kg*m/s^2)
        fgrav = mass*G;
        //calculate net force(kg*m/s^2)
        fnet = fgrav + fdrag;
        //decremement height by velocity(m/s)*timeStep(s) = displacement(m)
        height -= vel*timeStep;
        //increment time by timeStep
        time += timeStep;
    }

    //calculate terminal velocity
    termvel = sqrt((2*mass*G)/(dragCoefficient*crossSectionalArea*P));
    printf("\nTheoretical terminal velocity is %3.1f m/s\n", termvel);

  return EXIT_SUCCESS;
}