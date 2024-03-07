#!/usr/bin/env python
# -*- coding: utf-8 -*-
import requests


def download(page,f):
    data = {
        "limit": 20,
        "current": page
    }
    response = requests.post(url, headers=headers, data=data)

    if response.status_code == 200:
        try:
            info = response.json()
        except ValueError:
            print("无法解析为JSON")
    else:
        print("请求失败，状态码：", response.status_code)
    # info = response.json()
    for i in range(20):
        temp = []
        ##
        temp.append(info['list'][i]['pubDate'][:10])
        temp.append(info['list'][i]['prodName'])
        temp.append(info['list'][i]['place'])
        temp.append(info['list'][i]['lowPrice'])
        temp.append(info['list'][i]['highPrice'])
        temp.append(info['list'][i]['avgPrice'])
        temp.append("元/"+info['list'][i]['unitInfo'])
        f.write(" ".join(temp)+'\n')
    response.close()

def run(pages,f):
    for page in pages:
        print(page)
        download(page,f)

if __name__ == '__main__':
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36 Edg/105.0.1343.42',
        'Referer': 'http://www.xinfadi.com.cn/priceDetail.html' ##防盗链
    }
    url = "c"
    ##先访问一次，查看有多少页数据
    data = {
        "limit": 20,
        "current": 1
    }
    response = requests.post(url, headers=headers, data=data)
    info = response.json()
    num = info['count']
    response.close()
    pages = [i for i in range(1, num + 1)]
    f = open("Elite-class-development-training\\week5\\vegetable.log", "w+")
    run(pages,f)
    f.close()


# import requests
# from bs4 import BeautifulSoup


# def fetch_page(url):
#     try:
#         response = requests.get(url)
#         response.raise_for_status()  # 如果请求不成功，将抛出HTTPError异常
#         return response.text
#     except requests.RequestException as e:
#         print(f"Error fetching the page: {e}")
#         return None


# def parse_page(html_content):
#     soup = BeautifulSoup(html_content, "html.parser")
#     # 根据网页的实际结构，你可能需要调整下面的选择器
#     # 以下是一个示例，具体取决于网页上你想要提取的内容
#     price_details = soup.select(
#         "div.price-detail"
#     )  # 假设价格详情在一个class为'price-detail'的div标签内

#     for detail in price_details:
#         # 根据需要提取的信息，可能需要调整下面的代码
#         # 例如，如果价格在一个名为'price'的span标签内，你可以这样提取：
#         price = detail.select_one("span.price").text
#         print(price)


# def main():
#     url = "http://www.xinfadi.com.cn/priceDetail.html"
#     html_content = fetch_page(url)
#     if html_content:
#         parse_page(html_content)


# if __name__ == "__main__":
#     main()