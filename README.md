# sample-cppdotnet-cli
Dracal // SDK code sample for C++ (.NET) on CLI

## Assumptions

Running this repository requires you to have installed:
- .NET (version >= `8.0`)
- Visual Studio (version >= 2022)
- DracalView (version >= `3.2.x`)
  - Specifically, `dracal-usb-get` needs to be accessible from your `PATH` environment variable (more info in the [documentation how-to](https://www.dracal.com/en/programmers_howto/#dracal-usb-get)).

Script may need to be adjusted depending on your instrument's # of outputs _(currently assumed: 3 outputs)_. See script comments for details.


## Simple usage

Run by
- Using the **Play** button (Visual Studio)


## Sample output
<img src="https://github.com/Dracaltech/sample-node-vcp/assets/1357711/305ff9ae-2d98-4485-99a6-d09c02523d1e" width=400 />

```
PS C:\dev\dracal\sample-cppdotnet-cli> .\x64\Debug\sample-cppdotnet-cli.exe
Temperature (C): 101.99
RH..........(%): 20.68
Pressure..(kPa): 60.74
Temperature (F): 215.582
PS C:\dev\dracal\sample-cppdotnet-cli>

```
