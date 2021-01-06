/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface HtmlParser {
 *     public List<String> getUrls(String url) {}
 * }
 */

class Solution {
    public String getHostname(String url){
        int n = url.length();
        int end = 0;
        for(;end < n; end++){
            if(url.charAt(end) == '/' && url.charAt(end) == url.charAt(end+1)){
                end += 2;
                break;
            }
        }
        for(; end < n && url.charAt(end) != '/'; end++);
        return url.substring(0, end);
    }
    public List<String> crawl(String startUrl, HtmlParser htmlParser) {
        String hostname = getHostname(startUrl);
        List<String> res = new LinkedList<>();
        Queue<String> q = new LinkedList<>();
        q.add(startUrl);
        Set<String> vis = new HashSet<>();
        res.add(startUrl);
        vis.add(startUrl);
        while(!q.isEmpty()){
            String url = q.poll();
            for(String childUrl : htmlParser.getUrls(url)){
                if(!vis.contains(childUrl) && childUrl.startsWith(hostname)){
                    res.add(childUrl);
                    q.add(childUrl);
                    vis.add(childUrl);
                }
            }
        }
        return res;
    }
}