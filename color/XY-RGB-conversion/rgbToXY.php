<?php  
function rgbToXY($color)
{
foreach(['R','G','B'] as $val)
		{
		    //make range from 0 to 1
		    $color[$val]= $color[$val]/255;
		    //apply gamma correction for more vivid colors
		    $color[$val]=($color[$val]>0.04045)?pow(($color[$val]+0.055)/(1.0+0.055),2.4):($color[$val]/12.92);
		}
//convert to XYZ
$X=$color['R']* 0.649926+$color['G']*0.103455+$color['B']*0.197109;
$Y=$color['R']* 0.234327+$color['G']*0.743075+$color['B']*0.022598;
$Z=$color['R']* 0.000000+$color['G']*0.053077+$color['B']*1.035763;
if(($X+$Y+$Z)==0)
    {
        $xVal=0;
        $yVal=0;
        
    }else{
      //calculate XY vals
		$xVal=$X/($X+$Y+$Z);
		$yVal=$Y/($X+$Y+$Z);  
    }
// The Y of XYZvalue indicates the brightness of the converted color.
$bri= $Y;
return [$xVal,$yVal,$bri];
}
?>