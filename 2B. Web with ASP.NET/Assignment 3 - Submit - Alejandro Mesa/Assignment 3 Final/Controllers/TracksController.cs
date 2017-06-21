using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_3_Final.Controllers
{
    public class TracksController : Controller
    {
        private Manager m = new Manager();

        // GET: Tracks
        public ActionResult Index()
        {
            return View(m.TrackGetAll());
        }

        public ActionResult Pop()
        {
            return View(m.TrackPop());
        }

        public ActionResult DeepPurple()
        {
            return View(m.TrackDeepPurple());
        }

        public ActionResult Longest()
        {
            return View(m.TrackLongest());
        }

    }
}