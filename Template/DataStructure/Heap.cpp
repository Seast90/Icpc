struct heap {
	priority_queue< int > q1, q2;
	inline void push(int x){ q1.push(x); }
	inline void pop() { q2.push(x); }
	inline int top(){ erase(); return q1.top(); }
	inline int size(){ return q1.size() - q2.size(); }
	inline void erase(){
		while(q2.size() && q2.top() == q1.top()) q1.pop(), q2.pop();
	}
	inline int top2(){
		int x = top();
		q1.pop(); erase();
		int res = top(); push(x);
		return res;
	}
}
