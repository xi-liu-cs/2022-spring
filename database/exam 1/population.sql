drop table populations;

create table populations
(
    borough text,
    year int,
    fips_county_code int,
    nta_code text,
    nta text,
    population int,
    primary key(year, nta_code)
);

.mode csv
.import data/neighborhood_populations.csv populations