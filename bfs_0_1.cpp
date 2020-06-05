/*
    my logic
    since priority queue application -> to give shortest distance node first
    now if i get only two value then we can sort it in constant time by putting smaller in front and bigger in back
    see example
    if weight 0,x
    suppose in pq--> 0,0,x,x
    if two option after relation 0+0 or 0+x ---> in pq we push 0+x--> x still two element in pq
    or suppose pq--> x,x,x
    x+0,x+x--> pq--> x,x,2x still two element and back at weight of x
               
*/

vector<int> d(n, INF);
d[s] = 0;
deque<int> q;
q.push_front(s);
while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto edge : adj[v]) {
        int u = edge.first;
        int w = edge.second;
        if (d[v] + w < d[u]) {
            d[u] = d[v] + w;
            if (w == 1)
                q.push_back(u);
            else
                q.push_front(u);
        }
    }
}
