var Str = 011111101111110;
console.log("Before stuffing: " +  Str + " -- " + Str.length + " characters" );
var count = 0;
var Stuffing;
	for (var i = 0; i < Str.length; i++)
	{
        
		if (Str[i] == 1)
		{
			count ++;
		}
        if (count == 5)
		{
			Str.splice(i+1, 0, 0);
			count = 0;
		}
		else
		{
			Stuffing = Stuffing + Str[i];
			count += 1;
		}
	}
console.log("After stuffing:  " + Stuffing + " -- " + Stuffing.length + " characters");
console.log("After framing:   " + Str);