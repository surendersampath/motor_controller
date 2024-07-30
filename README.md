# Embedded Engineer - Coding Exercise

## To run the solution ->

## Usage - To compile and run the project inside a dev container ->

1. Ensure you have Docker for Desktop Running.
2. Re-open using the Dev Container extension in VS CODE.
3. You should see quick short cut buttons to Cmake and Run Application.

## Usage - To compile and run the project without a dev container ->
```
mkdir build
cd build 
cmake -DTARGET_GROUP=production ..
cmake .. 
cmake --build .

Run the main executable inside the build.
```

## Usage - To compile and run the test suite ->
```
mkdir build
cd build 
cmake -DTARGET_GROUP=test ..
cmake .. 
cmake --build .

Run the main executable inside the testsuite.
```
