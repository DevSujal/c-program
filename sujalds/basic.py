# import cmath
import cmath
# problem 1 :- roots of quadratic equation 
print("ax^2 + bx + c = 0")
a, b, c = input("enter the value of a b and c : ").split()
a = float(a)
b = float(b)
c = float(c)
if((b**2 - 4 *a *c) < 0):
    x1 = complex((-b + ( cmath.sqrt(b**2 - 4 *a *c)))/ (2 * a))
    x2 = complex((-b - ( cmath.sqrt(b**2 - 4 *a *c)))/ (2 * a))
else:
    x1 = (-b + ( cmath.sqrt(b**2 - 4 *a *c)))/ (2 * a)
    x2 = (-b - ( cmath.sqrt(b**2 - 4 *a *c)))/ (2 * a)   

print(f"the roots of {a}x^2 +{b}x + {c} = {x1}, {x2}")