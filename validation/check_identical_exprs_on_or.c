extern void bar(void);

static void foo(void *a, void *b, void *c)
{
	if (a || a)	/* should warn */
		bar();

	if (a || b)	/* should not warn */
		bar();

	if ((a == b) || (a == b))	/* should warn */
		bar();

	if ((a == b) || (b == c))	/* should not warn */
		bar();
}
/*
 * check-name: A warning should be issued for identical expressions on both sides of the '||' operator.
 *
 * check-error-start
check_identical_exprs_on_or.c:5:15: warning: identical expressions on both sides of '||'
check_identical_exprs_on_or.c:11:22: warning: identical expressions on both sides of '||'
 * check-error-end
 */
