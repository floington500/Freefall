# Freefall 


This is a text simulation of [freefall](https://en.wikipedia.org/wiki/Free_fall) I made as a mini project using formulas I learned from physics class in school.


## Usage


Using this program yourself is pretty simple (if you have experience with the command line of course), the binary can be executed like so:

```bash
./freefall 10
```

The number being passed in as a program argument is the height you want the object to be dropped from. 



## Demonstration





## How It Works


A few computations are made prior to the actual animation, which go along the lines of this:


1. Calculate initial velocity.
2. Use $V_i$ with the formula $v = \sqrt{i_v^2 + 2 * a * 2}$ to calculate velocity at each one second interval in the range of ${x | 0 \le x \le d}$.
3. Use the velocity results to calculate for time between each second with the formula $t = \frac{2d}{V_i + V_f}$ and add all the results to a vector, $vt$.


After all the computations are done, we can move onto the programming aspect and display the animation which is actually very simple:


1. Set up the console for the animation (see [setup](https://github.com/floington500/Freefall/blob/b6c49bed98d9e5c3834ae1e729cb0ba2b63012fd/src/main.cpp#L12) function).
2. Traverse **backwards** through the $vt$ and print a star at the start of every iteration.
   - Going through the vector forwards would give us an animation of the object falling really quickly then slowing down at the end because the time and velocity vectors are computed by using previous results to calculate the next one ($V_i$ and $V_f$) making them linear.
3. After printing the star, delay the program `vt[i]` seconds where `i` is the current index.
4. Remove the star and move the cursor down once in preparation for the next iteration.
5. Repeat this process until the end of `vt` is reached.


The code in main demonstrates this whole process pretty simply, so if you are a programmer looking for an easier explanation you can go there.

