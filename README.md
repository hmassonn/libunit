# libunit @ 42

![Where are the
tests?](https://www.commitstrip.com/wp-content/uploads/2017/02/Strip-Ou-sont-les-tests-unitaires-english650-final.jpg)

*Source: http://www.commitstrip.com/en/2017/02/08/where-are-the-tests/*

This is a small library developed at 42 to help with the task of unit testing.
It's tiny and doesn't have a lot of features, but it gets the job done.

# API Documentation
Your testing executable will run a list of **test suites**, which will run
**individual tests**. There are two kinds of tests: **simple**, which return 0
or -1 based on success, and **out**, which will capture `stdout` and check for a
predefined output.

* `make test` to launch all tests

There are also some functions to call from within your tests:

* real_test is an example of set test
