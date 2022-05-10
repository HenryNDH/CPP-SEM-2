/*  Declaration:
I declare that this test is my own work in accordance with Seneca College’s Academic Policies.  No part of this work has been copied manually or electronically from any other source
  (including 3rd party web sites) or distributed to other students.
I acknowledge that by beginning this test, I will abide by the above.
Name: Hoang Duy Nguyen
Student Number: 108397217
*/
function factor() 
{
  var pass = 0;
  var fail = 0;
  var Factor;
  var notFactor;
  var partial = 0;
  var time = 1;
  if (Number(arguments[arguments.length - 1] % Number(arguments[0]) == 0))
  {
    Factor = arguments[0];
    pass += 1;
    for (var i = 0 ; i < arguments.length -1; i++)
    {
      time = time * Number(arguments[i]);
      if (time != Number(arguments[arguments.length-1]))
      {
        partial +=1;
      }
      else 
      {
        partial = 0;
      }
    }
  }
  else
  {
    notFactor = arguments[0];
    fail += 1;
  }
  for (var i = 1; i < arguments.length - 1; i++ )
  {
    if (Number(arguments[arguments.length - 1] % Number(arguments[i]) == 0))
    {
      if (pass == 0)
      {
        Factor = arguments[i];
      }
      else
      {
        Factor = Factor + ","+ arguments[i];
      }
      pass += 1;
    }
    else  
    {
      if (fail == 0)
      {
        notFactor = arguments[i];
      }
      else
      {
        notFactor = notFactor + "," + arguments[i];
      }
        fail += 1;
    }
  }
  console.log("========== Factors ==========");
  if (fail == 0 && partial == 0)
  {
    console.log(Factor + " are complete factor(s) of " + Number(arguments[arguments.length - 1 ]) + ".");
  }
  else if ( fail != 0 && pass != 0)
  {
    console.log(Factor + " is(are) partial factor(s) of " + Number(arguments[arguments.length - 1 ]) + ".");
    console.log(notFactor + " is(are) not factor(s) of " + Number(arguments[arguments.length - 1 ]) + ".");
  }
  else if (fail != 0 && pass ==0)
  {
    console.log(notFactor + " is(are) not factor(s) of " + Number(arguments[arguments.length - 1 ]) + ".");
  }
  else if (fail == 0 || partial != 0 )
  {
    console.log(Factor + " are partial factor(s) of " + Number(arguments[arguments.length - 1 ]) + ".");
  }
}
factor(2,3)
factor(2,3,6);
factor(2,3,4,9);
factor(2,3,4,6,12);
factor(2,3,4,5);