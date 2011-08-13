extern void bar(void);

static void foo(void *a, void *b, void *c)
{
	void * d = a ? b : b; /* should warn */
}
/*
 * check-name: A warning should be issued for identical expressions on both the true and false branches of the '?:' operator.
 *
 * check-error-start
check_identical_exprs_on_cond.c:5:22: warning: identical expressions on both branches of '?:'
 * check-error-end
 */
