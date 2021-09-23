# Data-Model-and-Bindings
Tutorial on Euclid Data Model and Bindings
# Data Model

[Data model presentation](./Data_Model.pdf)
[Data model bindings tutorial](./DM_Bindings.pdf)

Please clone this repository with the following command:


Set up workdir:

```shell
> cd Work/Projects/
> mkdir workdir
> cd workdir
> mkdir data
```

Copy Data from irods to local workdir:
```shell
> wget -r -nc --no-check-certificate --user=sdcfr-read --password=password https://ccirdeuclid.in2p3.fr:443/euclid-fr/home/pfle3write/wl/2dmass-wl/DevWS7/ParamFile.xml
> wget -r -nc --no-check-certificate --user=sdcfr-read --password=password https://ccirdeuclid.in2p3.fr:443/euclid-fr/home/pfle3write/wl/2dmass-wl/DevWS7/InCatalog.xml
> wget -r -nc --no-check-certificate --user=sdcfr-read --password=password https://ccirdeuclid.in2p3.fr:443/euclid-fr/home/pfle3write/wl/2dmass-wl/DevWS7/InCatalog.fits
```
In current directory, you will find a new directory 

```shell
ccirdeuclid.in2p3.fr/euclid-fr/home/pfle3write/wl/2dmass-wl/DevWS7/
```
where you will find all these three files that you have downloaded.

Please copy xml files to your workdir and fits file to workdir/data
