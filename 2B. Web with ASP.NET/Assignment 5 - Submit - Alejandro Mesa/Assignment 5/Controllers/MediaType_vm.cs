using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace Assignment_5.Controllers
{
    public class MediaType_vm
    {
    }

    public class MediaTypeBase
    {
        public MediaTypeBase()
        {

        }
        [Key]
        public int MediaTypeId { get; set; }

        [Display(Name = "Media type")]
        public string Name { get; set; }
    }
}